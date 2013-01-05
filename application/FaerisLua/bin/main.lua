g_window:setSize(1024,800)
g_window:setCaption("FaerisGame")

g_render:setClearColor(Color(255,255,0))
g_render:clear(true)
g_render:swapBuffers()


mesh=MeshLoader:loadMesh("cube.msh");
if mesh==nil then 
	g_quit()
	return
end

g_render:translate()
mesh:draw(g_render);
g_render:swapBuffers();



