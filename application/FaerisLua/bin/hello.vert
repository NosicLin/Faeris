attribute vec3 a_vertex;
attribute vec3 a_color;

varying vec4 v_color;
void main()
{
	gl_Position=gl_ModelViewProjectionMatrix*vec4(a_vertex,1);
	v_color=vec4(a_color,1.0);
}

