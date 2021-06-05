def bind(app):
    app.bind("<Control-n>"    , new_file)
    app.bind("<Control-o>"    , open_file)
    app.bind("<Control-s>"    , save_file)
    app.bind("<Control-Alt-s>", save_as)
    app.bind("<Control-f>"    , find_func)
    app.bind("<Key>"          , auto_color)
    app.bind("<Control-z>"    , undo)
    app.bind("<Control-y>"    , redo)
