from bokeh.plotting import figure, show
import numpy as np

x = np.arange(1, 6)
y = np.random.rand(5) * 100 

plot = figure(title="Bar", x_axis_label="Data", y_axis_label="Results")

plot.vbar(x=x, top=y, width=0.5, bottom=0, color="purple")

show(plot)

# print(x)