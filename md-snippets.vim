au Filetype markdown inoremap <buffer> ,f <Esc>/<++><CR>:nohlsearch<CR>"_c4l
au Filetype markdown inoremap <buffer> ,k <Enter>$$<Enter><Enter>$$<Enter><++><Enter><Esc>3kA
au Filetype markdown inoremap <buffer> ,w <Esc>/ <++><CR>:nohlsearch<CR>"_c5l<CR>
" au Filetype markdown inoremap <buffer> ,n ---<Enter><Enter>
au Filetype markdown inoremap <buffer> ,b **** <++><Esc>F*hi
au Filetype markdown inoremap <buffer> ,s ~~~~ <++><Esc>F~hi
au Filetype markdown inoremap <buffer> ,i ** <++><Esc>F*i
au Filetype markdown inoremap <buffer> ,d `` <++><Esc>F`i
au Filetype markdown inoremap <buffer> ,c ```<Enter><++><Enter>```<Enter><Enter><++><Esc>4kA
au Filetype markdown inoremap <buffer> ,m - [ ] 
au Filetype markdown inoremap <buffer> ,p ![](<++>) <++><Esc>F[a
au Filetype markdown inoremap <buffer> ,a [](<++>) <++><Esc>F[a
au Filetype markdown inoremap <buffer> ,1 #<Space><Enter><++><Esc>kA
au Filetype markdown inoremap <buffer> ,2 ##<Space><Enter><++><Esc>kA
au Filetype markdown inoremap <buffer> ,3 ###<Space><Enter><++><Esc>kA
au Filetype markdown inoremap <buffer> ,4 ####<Space><Enter><++><Esc>kA
au Filetype markdown inoremap <buffer> ,l --------<Enter>

au Filetype markdown inoremap <buffer> ,r <ESC>:r ~/.config/nvim/cppfile/sol.markdown<CR>

au FileType markdown inoremap <buffer> ,n1 <div class="primary"><ENTER><ENTER></div><ENTER><ENTER><++><ESC>3kA
au FileType markdown inoremap <buffer> ,n2 <div class="secondary"><ENTER><ENTER></div><ENTER><ENTER><++><ESC>3kA
au FileType markdown inoremap <buffer> ,n3 <div class="danger"><ENTER><ENTER></div><ENTER><ENTER><++><ESC>3kA
au FileType markdown inoremap <buffer> ,n4 <div class="warning"><ENTER><ENTER></div><ENTER><ENTER><++><ESC>3kA
au FileType markdown inoremap <buffer> ,n5 <div class="info"><ENTER><ENTER></div><ENTER><ENTER><++><ESC>3kA
au FileType markdown inoremap <buffer> ,n6 <div class="light"><ENTER><ENTER></div><ENTER><ENTER><++><ESC>3kA
au FileType markdown inoremap <buffer> ,n7 <div class="success"><ENTER><ENTER></div><ENTER><ENTER><++><ESC>3kA
