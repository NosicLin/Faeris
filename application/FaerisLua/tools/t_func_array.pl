#/usr/bin/perl 
#this a bug about tolua++
#if we write a pkg function like this 
#  function( unsigned int  v[count],int count)
# 
#  it will translate the array  v like  this 
#  		unsigned int* v = Mtolua_new_dim(int, count);
#   or 
# 		unsigned int* v = (int*) malloc((count)*sizeof(int)); 
#
#  compile it as error 
#  so need to replace it  with 
#  		unsigned int* v = Mtolua_new_dim(unsigned int,count);
#  or 
#  		unsigned int* v = (unsigned int*) malloc(count)*sizeof(int);
#

while($line=<STDIN>){
	if( $line=~ /unsigned int\* v = Mtolua_new_dim\(int/)
	{
		$line=~ s/unsigned int\* v = Mtolua_new_dim\(int/unsigned int* v = Mtolua_new_dim\(unsigned int/;
	}
	print $line;
}









