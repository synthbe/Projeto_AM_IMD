from bokeh.plotting import figure, show

x = [1, 2, 3, 4, 5]
y = [6, 7, 2, 4, 5]
y1 = [2, 3, 4, 5, 6]
y2 = [4, 5, 5, 7, 2]

# Creating a new plot with a title and axis label
p = figure(title="Multiple line example", x_axis_label='x', y_axis_label='y')

# Adding multiples renderers
p.line(x, y, legend_label="Temp", line_width=2)
p.line(x, y1, legend_label="Rate", color="red", line_width=2)
p.line(x, y2, legend_label="Objects", color="green", line_width=2)

#Show plot
show(p)


# Preparing the data
# You used a plain Python list, but other forms of serialized data work as well.

# Calling the figure() function
# This creates a plot with the most common default options. You can customize various properties of your plot, such as its title, tools, and axes labels.

# Adding renderers
# You used line() to create a line. Renderers have various options that allow you to specify visual attributes such as colors, legends, and widths.

# Asking Bokeh to show() or save() the results
# These functions either save your plot to an HTML file or display it in a browser.