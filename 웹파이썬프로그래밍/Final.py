class Guest:
    def __init__(self):
        self.id = 'none'
        self.level = 0
    def getGuestLevel(self):
        return self.level
    def getGuestInfo(self):
        return self.id, self.level
    def setGuestInfo(self, id, level):
        self.id = id
        self.level = level
    def __str__(self):
        return '<' + self.id + ':%d>'%self.level

class Queue:
    def __init__(self):
        self.q = []
    def getGuestQueue(self):
        if self.q == []:
            return self.q != []
        else:
            return self.q
    def getGuestNumber(self):
        if self.q == []:
            return self.q != []
        else:
            return len(self.q)
    def getFirstGuestId(self):
        if self.q == []:
            return self.q != []
        else:
            return self.q[0].id
    def serveGuest(self):
        if self.q == []:
            return self.q != [], 0, 0
        else:
            self.q.reverse()
            self.firstguest = self.q.pop()
            self.q.reverse()
            return self.q != [], self.firstguest, len(self.q)
    def cancelGuest(self, tid):
        if self.q == []:
            return self.q != [], 0, 0
        for a in range(len(self.q)):
            if self.q != [] and self.q[a].id != tid:
                return self.q != [], 0, 0
            elif self.q != [] and self.q[a].id == tid:
                self.q.remove([self.q[a]])
                return 1==1, self.q[a], len(self.q)

class FifoQueue(Queue):
    def receiveGuest(self, guest):
        self.q.append(guest)
        return len(self.q) - 1

class PriorityQueue(Queue):
    def receiveGuest(self, guest):
        self.level_list = []
        self.new_q = []
        self.wanted_guest_number = 0
        self.q.append(guest)
        for a in range(len(self.q)):
            self.level_list.append(self.q[a].level)
        self.level_list.sort(reverse=True)
        for a in range(len(self.level_list)):
            for b in range(len(self.q)):
                if self.level_list[a] == self.q[b].level:
                    self.new_q.append(self.q[b])
        self.q = self.new_q
        for a in range(len(self.q)):
            if guest == self.q[a]:
                self.wanted_guest_number = a
        return self.wanted_guest_number
            
