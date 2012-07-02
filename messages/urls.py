from django.conf.urls import patterns, include, url
from django.views.generic import DetailView, ListView
from messages.models import *

urlpatterns = patterns('messages.views',
    # url(r'^$', ListView.as_view(
    #         queryset=Message.objects.order_by('-date_added')[:5],
    #         context_object_name='latest_msgs',
    #         template_name='messages/index.html'), name='root'),

    # url(r'^(?P<pk>\d+)/$',  DetailView.as_view(
    #         model=Message,
    #         template_name='messages/detail.html') ),
    #url(r'^(?P<m_id>\d+)/$', 'detail'),

    url(r'^$', 'index'),
    
    url(r'^add/', 'add'),

    url(r'^(?P<m_id>\d+)/vote/$', 'vote'),
)
