dofile("script/SceneStartWM.lua")
dofile("script/SceneAboutWM.lua")
dofile("script/ScenePlayWM.lua")

-- 一堆东西在上面
local directorWM = share:director() -- 一个游戏中只存在一个 director
local sceneWM = SceneMainMenu()
directorWM:run(sceneWM)