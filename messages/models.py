from django.db import models
from datetime import datetime

class Message(models.Model):
    text = models.CharField(max_length=200)
    votes = models.IntegerField()
    date_added = models.DateTimeField(default=datetime.now)
    score = models.BigIntegerField()
    next_vote = models.IntegerField(default=60000)

    def __unicode__(self):
        return self.text + ' : '+ str(self.votes) + ' : '+str(self.date_added) + ' : ' + str(self.score) + ' : '+str(self.next_vote) + '\n'
