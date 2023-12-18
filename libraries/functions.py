from bokeh.plotting import figure, show
from bokeh.layouts import row
import numpy as np

x = np.arange(1, 11, 000.1)

# print(x)

sin = np.sin(x)
cos = np.cos(x)
tan = np.tan(x)

s = figure()
s.line(x, sin, legend_label="Sin")

c = figure()
c.line(x, cos, legend_label="Cos")

t = figure()
t.line(x, tan, legend_label="Tang")

show(row(children=[s, c, t], sizing_mode="scale_width"))