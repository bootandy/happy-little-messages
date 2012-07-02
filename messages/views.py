# Create your views here.
from django.shortcuts import render_to_response, get_object_or_404
from django.http import HttpResponseRedirect, HttpResponse
from django.core.urlresolvers import reverse
from messages.models import Message
from django.http import Http404
from django.template import RequestContext


def index(request):
    latest_msgs = Message.objects.all().order_by('-votes')[:5]
    return render_to_response('messages/index.html', 
        {'latest_msgs': latest_msgs}, 
        context_instance=RequestContext(request))

def load(request):
    latest_msgs = Message.objects.all().order_by('votes')[:10]


# def detail(request, m_id):
#     m = get_object_or_404(Message, pk=m_id) # get_list_or_404 also works :-)
#     return render_to_response('messages/detail.html', {'message': m},  context_instance=RequestContext(request))

def add(request):
    text = request.REQUEST['main_message_input']
    m = Message(text=text, votes=0)
    m.save()
    return HttpResponseRedirect(reverse('messages.views.index'))

def vote(request, m_id):
    p = get_object_or_404(Message, pk=m_id)
    try:
        p.votes += 1
        p.save()
    except (KeyError, Choice.DoesNotExist):
        # Redisplay the poll voting form.
        return render_to_response('messages/index.html', {
            'message': message,
            'error_message': "Error saving!",
        }, context_instance=RequestContext(request))
    else:
        # Always return an HttpResponseRedirect after successfully dealing
        # with POST data. This prevents data from being posted twice if a
        # user hits the Back button.
        return HttpResponseRedirect(reverse('messages.views.index'))

