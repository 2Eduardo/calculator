subdir('parser')

incdir = include_directories('parser')

sources = [
  'main.c',
  'app.c',
  'main_window.c'
]

# Compile resources
sources += gnome.compile_resources(
  'calculator_resource',
  'calculator.gresource.xml',
  source_dir: ['ui', '../data']
)

calculator = executable(
  meson.project_name(),
  sources,
  dependencies: calculator_deps,
  link_with: parser_lib,
  include_directories: incdir
)
