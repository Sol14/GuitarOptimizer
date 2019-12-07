import statistics
class Chord(object):

    #Chord constructor
    #Args
    #arg1 label/chord
    #arg2 list of fingers
    #
    #elements
    #label: Chord name
    #positions: p0, p1, p2
    #as hand positions
    def __init__(self, arg1=None, arg2=None):
        if arg1 and arg2:
            self.label = arg1
            self.positions = []
            self.set_weights(arg2)
        elif arg1:
            self.label = arg1.label
            self.positions = arg1.positions

    #Sets 3 positions based on average weight
    #first element must be added to every
    #element on list
    def set_weights(self, position):
        for i in range(0, 3):
            mean = 0
            for j in range(1, len(position)):
                if not position[j] == 0:
                    position[j] = position[j] + position[1]
            position = position[1:len(position)]
            mean = statistics.mean(position[6*i: 6*i+6])
            if mean == 0:
                self.positions.append(-1)
            else:
                self.positions.append(mean)
