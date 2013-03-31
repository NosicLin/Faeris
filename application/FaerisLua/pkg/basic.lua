
_is_functions = _is_functions or {}
_to_functions = _to_functions or {}
_push_functions = _push_functions or {}

local fsobject= {
	"TextureMgr",
	"TouchEventListener",
	"FontTTF",
	"Scheduler",
	"Entity",
	"SchedulerTarget",
	"Director",
	"Scene",
	"Layer",
	"Texture2D",

	"LuaEntity",
	"LuaColorLayer",
	"Render",
	"SysDispatcher",
	"Quad2D",
	"Window",
	"TouchDispatcher",
	"Layer2D",
	"LuaLayer2D",
	"FsObject",
	"ResourceMgr",
	"LuaScene",
	"FsArray",
	"LuaColorQuad2D",
	"SysEventListener",
	"LuaTouchEventListener",
	"LabelTTF",
	"LuaSysEventListener",
	"LuaQuad2D",
}


-- register CCObject types
for i = 1, #fsobject do
	_push_functions[fsobject[i]] = "toluaext_pushfsobject2"
end

-- register LUA_FUNCTION, LUA_TABLE, LUA_HANDLE type
_to_functions["LUA_FUNCTION"] = "toluaext_to_luafunction"
_is_functions["LUA_FUNCTION"] = "toluafix_is_luafunction"

_to_functions["LUA_TABLE"] = "toluaext_to_luatable"
_is_functions["LUA_TABLE"] = "toluaext_is_luatable"
_push_functions["LUA_TABLE"] = "toluaext_push_luatable"

local toWrite = {}
local currentString = ''
local out
local WRITE, OUTPUT = write, output

function output(s)
	out = _OUTPUT
	output = OUTPUT -- restore
	output(s)
end

function write(a)
	if out == _OUTPUT then
		currentString = currentString .. a
		if string.sub(currentString,-1) == '\n'  then
			toWrite[#toWrite+1] = currentString
			currentString = ''
		end
	else
		WRITE(a)
	end
end

function post_output_hook(package)
	local result = table.concat(toWrite)
	local function replace(pattern, replacement)
		local k = 0
		local nxt, currentString = 1, ''
		repeat
			local s, e = string.find(result, pattern, nxt, true)
			if e then
				currentString = currentString .. string.sub(result, nxt, s-1) .. replacement
				nxt = e + 1
				k = k + 1
			end
		until not e
		result = currentString..string.sub(result, nxt)
		if k == 0 then print('Pattern not replaced', pattern) end
	end


	replace([[toluaext_push_luatable(tolua_S,(void*)&self->m_data,"LUA_TABLE");]],
	[[toluaext_push_luatable(tolua_S,self->m_data);]]);

	replace([[self->m_data = *((LUA_TABLE*)  toluaext_to_luatable(tolua_S,2,0))]],
	[[if(self->m_data!=-1) toluaext_remove_luatable(tolua_S,self->m_data); 
	self->m_data=toluaext_to_luatable(tolua_S,2,0)]])

	replace([[tolua_usertype(tolua_S,"LUA_TABLE");]], [[]])

	for i=1,#fsobject do 
		cur_object=fsobject[i];
		replace("tolua_usertype(tolua_S,\""..cur_object.."\");",
				"toluaext_fsobject(tolua_S,\""..cur_object.."\");")
	end



	WRITE(result)
end


















