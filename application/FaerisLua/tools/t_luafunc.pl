#/usr/bin/perl

#Pair:
# 	find: tolua_isusertype(tolua_S,*,"LUA_FUNCTION",*) 
# 	replace: tolua_fs_isfunction(tolua_S,*,"LUA_FUNCTION",*)

#Pair:
#	find; LUA_FUNCTION refid = *((LUA_FUNCTION*))  tolua_tousertype
#   replace: LUA_FUNCTION refid = *((LUA_FUNCTION*)) tolua_fs_toreffunction

while ($line=<STDIN>) {
	if( $line =~ /tolua_usertype\(tolua_S,\"LUA_FUNCTION\"\)/ )
	{
		next;
	}

	if( $line =~ /tolua_isusertype\(tolua_S,\d+,\"LUA_FUNCTION\",\d+,&tolua_err/)
	{
		$line =~ s/tolua_isusertype/tolua_fs_isfunction/;
	}
	elsif ( $line =~ /LUA_FUNCTION refid = \*\(\(LUA_FUNCTION\*\)  tolua_tousertype\(tolua_S,\d+,\d+\)\)/)
	{
		$line =~ s/tolua_tousertype/tolua_fs_to_reffunction/;
		$line =~ s/\*\(\(LUA_FUNCTION\*\)/\(\(LUA_FUNCTION\)/
	}
	print $line
}
