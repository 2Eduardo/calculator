project(
  'calculator', 
  'c',
  version : '0.1'
)

cc = meson.get_compiler('c')
gnome = import('gnome')

# Dependencies
gtk = dependency('gtk+-3.0')
glib = dependency('glib-2.0')
m_dep = cc.find_library('m', required: true)

calculator_deps = [
  gtk,
  glib,
  m_dep
]

# Optional Tools
xmllint = find_program('xmllint', required: false)
xsltproc = find_program('xsltproc', required: false)

# Directories
data_dir = join_paths(meson.source_root(), 'data')

# Ṣubfolders
subdir('data')
subdir('src')
