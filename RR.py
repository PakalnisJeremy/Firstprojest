# -*- coding: utf-8 -*-
"""
Created on Thu Mar 27 08:55:45 2018

@author: sflor
"""
from random import *


class Process:

    def __init__(self, id):
        self.id = id
        self.serviceTime = randint(2, 5)
        self.arrivalTime = randint(0, 100)
        self.currentTime = self.serviceTime
        self.complete = False
        self.endTime = None
        self.initialWait = None
        self.startTime = None

    def run_process(self, time, quantum):
        if(self.currentTime == self.serviceTime):
            self.startTime = time
            self.initialWait = time - self.arrivalTime

        self.currentTime = self.currentTime - quantum
        time = time + quantum
        self.is_complete(time)
        if(self.complete):
            return (time - abs(self.currentTime))
        else:
            return (time)

    def is_complete(self, time):
        if(self.currentTime <= 0):
            self.complete = True
            self.endTime = time

    def __str__(self):
        return "ID [%s], Arrival Time [%s], Service Time [%s], End Time [%s], Initial Wait [%s], Start Time [%s]" % (self.id, self.arrivalTime, self.serviceTime, self.endTime, self.initialWait, self.startTime)


def readyJobs(objs, time):
    readyJobs = 0
    for obj in objs:
        if(obj.arrivalTime <= time):
            readyJobs = readyJobs + 1

    if(readyJobs >= 0):
        return (True)
    else:
        return (False)


