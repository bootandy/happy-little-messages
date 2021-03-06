# Create your views here.
from django.shortcuts import render_to_response, get_object_or_404
from django.http import HttpResponseRedirect, HttpResponse
from django.core.urlresolvers import reverse
from messages.models import Message
from django.http import Http404
from django.template import RequestContext

import urllib
import time

NUM_MSGS_TO_LOAD = 25

def index(request):
    page_to_load = int(request.GET.get('pages', 0))
    scroll_top = int(request.GET.get('scroll_top', 0))
    notification = urllib.unquote(request.GET.get('notification',''))

    latest_msgs = Message.objects.all().order_by('-score')[:(page_to_load+NUM_MSGS_TO_LOAD)]

    votes = request.COOKIES.get('voted_for','').split(',')
    votes = filter(None, votes)
    vote_list = map(lambda a: int(a), votes);

    return render_to_response('messages/index.html',  {
        'latest_msgs':latest_msgs,
        'page_to_load':(page_to_load+NUM_MSGS_TO_LOAD),
        'scroll_top':scroll_top,
        'votes': vote_list,
        'notification':notification
        },
        context_instance=RequestContext(request))

def add(request):
    text = request.REQUEST['main_message_input']
    if '<a' in text:
        return HttpResponseRedirect('/?notification='+urllib.quote('No <a href=> links please. You might be a spam bot'))

    m = Message(text=text, votes=0, score=time.mktime(time.gmtime()))
    m.save()
    #return HttpResponseRedirect(reverse('messages.views.index'))
    return HttpResponseRedirect('/?notification='+urllib.quote('you added: '+m.text))

def vote(request, m_id):
    p = get_object_or_404(Message, pk=m_id)
    try:
        p.votes += 1
        p.score += p.next_vote
        #p.next_vote = int(p.next_vote * 2 / 3)
        p.next_vote = max(p.next_vote - 10, 10)
        p.save()

    except (KeyError):
        # Redisplay the poll voting form.
        return render_to_response('messages/index.html', {
            'message': message,
            'error_message': "Error saving!",
        }, context_instance=RequestContext(request))
    else:
        res = HttpResponseRedirect('/?notification='+urllib.quote('you voted for: '+p.text) )

        votes = request.COOKIES.get('voted_for','') + ',' + str(p.id)
        res.set_cookie('voted_for', votes)
        return res

