--void test translate 

dofile("draw_aux.lua");
g_window:setSize(1024,800)
g_window:setCaption("FaerisGame")


g_render:setClearColor(Color(0,0,0))
g_render:clear(true)
g_render:swapBuffers()
g_render:setViewport(0,0,1024,800)
g_frame:setFPS(0)

mat=Matrix4()
mat:makeOrthographic(-2,2,-2,2,0,100);
g_render:setProjectionMatrix(mat);


g_render:clear(true)

local function onFrameEnd(diff)
	--print( "update"..diff.."FPS:"..g_frame:getAvgFPS())
	g_render:pushMatrix();
	g_render:clear(true)

	--Used to Test translate 
	--draw_test_make_translate();
	--draw_test_make_rotate()
	--draw_test_make_rotate_from_euler()
	draw_test_transform()
	--draw_test_mul()
	g_render:popMatrix();
	g_render:swapBuffers();
end






local function onFrameUpdate(diff)
end

frame_listener=FrameListener()


frame_listener:registerUpdateFunc(onFrameUpdate)
frame_listener:registerEndFunc(onFrameEnd)


g_frame:addListener(frame_listener);


