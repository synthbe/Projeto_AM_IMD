import pandas_datareader as web
import numpy as np
from bokeh.plotting import figure, show
from bokeh.models import Div, Spinner, TextInput # ColumnarDataSource
from bokeh.layouts import layout

# df = web.DataReader("MSFT", "yahoo")

# source = ColumnarDataSource(data=df)

# p = figure()

# p.line(x="Date", y="Close", source=source)

# show(p)

x = np.arange(50)
y = np.random.rand(50)

p = figure()
points = p.circle(x, y)

div = Div(text="<p>Select Size</p>")

spinner = Spinner(title="Circel size", low=0, high=20, step=1, value=points.glyph.size, width=200)
spinner.js_link("value", points.glyph, "size")

textinput = TextInput(value=points.glyph.fill_color, width=200)
textinput.js_link("value", points.glyph, "fill_color")

l = layout([[div, spinner], [textinput], [p]])

show(l)