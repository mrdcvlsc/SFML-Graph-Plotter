# TODO

1. [ ] Organize the grid class
2. [ ] Add a method that will convert a given "gird/cartesian coordinate point" to its equivalent "window position". e.g.

    Giving `cartesian coordinate vector (0, 0)` will be converted to a `vector (250, 250)` if the window's demension is `500x500`.
3. [ ] Create a Grid Element Abstract Class that will be use to create derive entities that we can draw to the graph, each derived entities should be stored as a child of the grid class then iterate and draw those children when the draw function is called.
    1. [ ] `Point` Derived Class - draw a point in the graph.
    2. [ ] `Line` Derived Class - given a sets of different points, draw a line to the graph by tracing the each points in sequence.
    3. [ ] `Function` Derived Class - extends the `Line` derived class, has the functionality to draw a function in the graph.
