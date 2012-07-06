from django.conf.urls import patterns, include, url
from django.contrib.staticfiles.urls import staticfiles_urlpatterns


from django.contrib import admin
admin.autodiscover()

urlpatterns = patterns('messages.views',
	url(r'^$', 'index'),
	url(r'^add/', 'add'),
    url(r'^(?P<m_id>\d+)/vote/$', 'vote'),
    url(r'^admin/', include(admin.site.urls)),
)

urlpatterns += staticfiles_urlpatterns()
