project('DSAcourse', 'c')
cc = meson.get_compiler('c')
mdep = cc.find_library('m')
executable('dsa.out',
'stack/stack.c', 'queue/queue.c', 'sparsematrix/sparsematrix.c', 'binarytree/completebinarytree.c', 'binarytree/threadedbinarytree.c',
'binarytree/heap.c',
'main.c',
dependencies: mdep)
