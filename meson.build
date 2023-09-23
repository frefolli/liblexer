project('liblexer', 'cpp', version: 'master')

include = include_directories('include')

main = executable('main.exe', [
    'src/main.cc',
    'src/tests/calc.cc',
  ], include_directories : include)

liblexer_dep = declare_dependency(
  include_directories : include)
