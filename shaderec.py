import numpy as np
from utilities.normal import Normal

class ShadeRec:
    def __init__(self, world) -> None:
        self.w = world
        self.hit_an_object = False
        self.normal = Normal()