# subdir('parser')

sources = [
  'main.c',
  'app.c',
  'main_window.c',
  'parser/math_parse.c',
  'parser/math_token.c',
  'parser/math_operations.c'
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
  c_args: ['-I../src/include', '-I../src/parser']
)
