from django.db import models

class Message(models.Model):
    text = models.CharField(max_length=200)
    votes = models.IntegerField()
    date_added = models.DateField()

    def __unicode__(self):
        return self.text + ' : '+ str(self.votes) + ' : '+str(self.date_added)
