'''
Este código proviene de este repositorio:
https://github.com/LCKYN/manim-101/blob/main/Estimating%20Pi%20using%20Monte%20Carlo/video.py

y simplemente lo he modificado a mi gusto y compilado para generar el vídeo. No soy el autor del código
'''

from manim import *
import numpy as np
import random as ran


class MonteCarlo(Scene):
    def construct(self):


        radius_ = 3.3

        offset_ = 0
        offset = (offset_, 0, 0)

        circle = Circle(radius=radius_, color=RED)
        circle.move_to(offset)

        square = Rectangle(width=radius_*2, height=radius_*2)
        square.move_to(offset)

        self.add(circle)
        self.add(square)
        self.wait(1)

        point_text, point_number = point_label = VGroup(
            Text("ptos totales: ", font_size=30),
            DecimalNumber(
                0,
                show_ellipsis=False,
                num_decimal_places=0
            )
        )

        in_text, in_number = in_label = VGroup(
            Text("ptos dentro: ", font_size=30),
            DecimalNumber(
                0,
                show_ellipsis=False,
                num_decimal_places=0
            )
        )

        pi_text, pi_number = pi_label = VGroup(
            Tex(r"$\pi\approx$ ", font_size=40),
            DecimalNumber(
                0,
                show_ellipsis=True,
                num_decimal_places=4
            )
        )
        point_label.arrange(RIGHT)
        in_label.arrange(RIGHT)
        pi_label.arrange(RIGHT)

        point_label.move_to((radius_-1, radius_+0.3, 0))
        in_label.move_to((-radius_+1, radius_+0.3, 0))
        pi_label.move_to((0, -radius_-0.5, 0))

        self.add(point_label, in_label, pi_label)
        self.wait(2)
        count_all = 0
        c = 0
        apx_pi = 0

        point_number.add_updater(lambda m: m.set_value(count_all))
        in_number.add_updater(lambda m: m.set_value(c))
        pi_number.add_updater(lambda m: m.set_value(apx_pi))

        ran.seed(1)
        iterations_ =  6001
        for i in range(iterations_):
            pos = (-offset_-radius_ + ran.random() * radius_*2, -radius_ + ran.random() * radius_*2, 0)
            if((pos[0] - offset_) ** 2 + pos[1] ** 2 < radius_**2):
                d = Dot(color=RED, radius = 0.04)
                c += 1
            else:
                d = Dot(color=GREEN, radius = 0.04)
            d.move_to(pos)
            if i%3==0:
                self.play(Create(d, run_time=0.03))
            else:
                self.add(d)
            count_all = i
            apx_pi = c/(i+1) *4 
        self.wait(1)