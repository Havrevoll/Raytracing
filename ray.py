import numpy as np

class Ray:
    def __init__(self, origin = np.zeros(3), dir = np.array([0.0, 0.0, 1.0])):
        self.o = origin
        self.d = dir
