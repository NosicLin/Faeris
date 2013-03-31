share:scheduler():stop();

for i=0,40000 do 
	entity=Entity:create()
	entity2=Entity:create()
	entity:addChild(entity2)
	layer=Layer2D:create()
	layer:add(entity)

end
entity=nil
entity2=nil
layer=nil
_G={}
for i=1,100 do 
	collectgarbage("collect")
	collectgarbage("collect")
	collectgarbage("collect")
	collectgarbage("collect")
	collectgarbage("collect")
	collectgarbage("collect")

end 

