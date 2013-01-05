main:
	./luabind++.exe -o temp  FsFaeris.pkg
	cat temp | perl ../tools/t_luafunc.pl  >FsLuaFaeris.cc 
	rm -f temp
	cp FsLuaFaeris.cc ../src/FsLuaFaeris.cc 
	cp FsLuaFaeris.cc ../tools/FsLuaFaeris.cc 
