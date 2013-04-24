
GAME_STATE = {STATE_GAMEMAINMENU = 0, -- 相当于主要的界面有3个
				STATE_GAMEPLAY = 1,
				STATE_GAMEABOUT = 2, }

g_function = {} -- 声明一个表
function g_function.ChangeLayoutCallBack(self, someCBList)
	local data = self.data -- 为了下面方便书写
	
	if data == nil then
		return
	end
	
	data.onUpdate = someCBList.onUpdate
	data.onTouchBegin = someCBList.onTouchBegin
	data.onTouchMove = someCBList.onTouchMove
	data.onTouchEnd = someCBList.onTouchEnd
end

-- 一堆东西在上面
local directorWM = share:director(); -- 一个游戏中只存在一个

function CreateMainMenuData() -- Create function only run once
	local spriteBK = Sprite2D:create("sprites/start.fst")
	local quad2DPlay = Quad2D:create("textures/play.png", 122, 43)
	local quad2DQuit = Quad2D:create("textures/quit.png", 122, 43)
	local quad2DSetting = Quad2D:create("textures/settings.png", 270, 46)
	
	quad2DPlay:setPosition(480, 240) -- the play button's position
	quad2DQuit:setPosition(480, 180) -- the quit button's position
	quad2DSetting:setPosition(480, 120) -- the setting button's position
	
	local data = {}
	
	data.quad2DFocus = nil
	data.quad2DPlay = quad2DPlay
	data.quad2DQuit = quad2DQuit
	data.quad2DSetting = quad2DSetting
	data.spriteBK = spriteBK
	
	return data
end

function CreateMainMenuUpdate(selfLayout, dt) -- selfLayout 为 Layer2D
	selfLayout:update(dt) 
	local total_frame = selfLayout.data.spriteBK:getTotalFrame()
	local cur_frame = selfLayout.data.spriteBK:getCurFrame()

	if total_frame - 2 == cur_frame then
		selfLayout.data.quad2DPlay:setVisible(true)
		selfLayout.data.quad2DQuit:setVisible(true)
		selfLayout.data.quad2DSetting:setVisible(true)
		selfLayout:setTouchEnabled(true)
	end
end

function CreateMainMenuLayoutEnter(selfLayout)
	print("run CreateMainMenuLayoutEnter(selfLayout)")
	selfLayout.data.quad2DPlay:setVisible(false)
	selfLayout.data.quad2DQuit:setVisible(false)
	selfLayout.data.quad2DSetting:setVisible(false)
	selfLayout.data.spriteBK:setAnimation("default")
	selfLayout.data.spriteBK:startAnimation(Sprite2D.ANIM_END)
	selfLayout.data.onUpdate = CreateMainMenuUpdate
	selfLayout:setTouchEnabled(false)
end

function MainMenuTouchBFun(selfLayout, x, y) -- self 为 Layer2D
	local x, y = selfLayout:toLayerCoord(x, y)
	local quad2DTemp = selfLayout.data.quad2DFocus
	
	if selfLayout.data.quad2DPlay:hit2D(x, y) then
		selfLayout.data.quad2DFocus = selfLayout.data.quad2DPlay
	elseif selfLayout.data.quad2DQuit:hit2D(x, y) then
		selfLayout.data.quad2DFocus = selfLayout.data.quad2DQuit
	elseif selfLayout.data.quad2DSetting:hit2D(x, y) then
		selfLayout.data.quad2DFocus = selfLayout.data.quad2DSetting
	else
		selfLayout.data.quad2DFocus = nil
	end
	
	if quad2DTemp ~= selfLayout.data.quad2DFocus then
		if quad2DTemp ~= nil then
			quad2DTemp:setScale(1, 1, 1)
		end
		if selfLayout.data.quad2DFocus ~= nil then
			selfLayout.data.quad2DFocus:setScale(2, 2, 1)
		end
	end
end

function MainMenuTouchEFun(selfLayout, x, y)
	local x, y = selfLayout:toLayerCoord(x, y)
	local quad2DTemp = selfLayout.data.quad2DFocus
	
	if selfLayout.data.quad2DPlay:hit2D(x, y) then
		selfLayout.data.quad2DFocus = selfLayout.data.quad2DPlay
	elseif selfLayout.data.quad2DQuit:hit2D(x, y) then
		selfLayout.data.quad2DFocus = selfLayout.data.quad2DQuit
	elseif selfLayout.data.quad2DSetting:hit2D(x, y) then
		selfLayout.data.quad2DFocus = selfLayout.data.quad2DSetting
	else
		selfLayout.data.quad2DFocus = nil
	end
	
	if quad2DTemp ~= nil then
		quad2DTemp:setScale(1, 1, 1)
	end
	
	if selfLayout.data.quad2DFocus ~= nil then
		selfLayout.data.quad2DFocus:setScale(1, 1, 1)
		selfLayout.data.quad2DFocus = nil
		print("you have select a button")
	end
end

function CreateGameMainMenuLayout()
	print("CreateGameMainMenuLayout()")
	local layoutMainUI = Layer2D:create(); -- 图层

	layoutMainUI:setViewArea(0, 0, 960, 640)
	layoutMainUI.data = CreateMainMenuData() -- 如果不加括号就是函数指针，切忌
	layoutMainUI.data.onEnter = CreateMainMenuLayoutEnter -- 这里有个刚开始的onUpdata
	layoutMainUI.data.onTouchBegin = MainMenuTouchBFun
	layoutMainUI.data.onTouchMove = MainMenuTouchBFun
	layoutMainUI.data.onTouchEnd = MainMenuTouchEFun

	return layoutMainUI
end

function CreateSceneMainData()
	data.layoutMain = CreateGameMainMenuLayout()
	return data
end

function CreateMainMenuSceneEnter(selfScene)
	print("run CreateMainMenuSceneEnter(selfScene)")
	selfScene:push(selfScene.data.layoutMain)
	selfScene.data.layoutMain.data:onEnter()
end

function CreateGameMainMenuScene()
	print("run CreateGameMainMenuScene()")
	local sceneMainUI = Scene:create()
	sceneMainUI.data = CreateSceneMainData()
	sceneMainUI.data.onEnter = CreateMainMenuSceneEnter
	return sceneMainUI
end

directorWM:run(CreateGameMainMenuScene())
