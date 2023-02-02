-- local setup, dashboard = pcall(require, "dashboard-nvim")
-- if not setup then
-- 	print("Not dashboard")
-- 	return
-- end

-- local dashboard = require("dashboard-nvim")

local header = {
	"⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣠⣤⣤⣴⣦⣤⣤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ",
	"⠀⠀⠀⠀⠀⠀⢀⣤⣾⣿⣿⣿⣿⠿⠿⠿⠿⣿⣿⣿⣿⣶⣤⡀⠀⠀⠀⠀⠀⠀ ",
	"⠀⠀⠀⠀⣠⣾⣿⣿⡿⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⢿⣿⣿⣶⡀⠀⠀⠀⠀ ",
	"⠀⠀⠀⣴⣿⣿⠟⠁⠀⠀⠀⣶⣶⣶⣶⡆⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⣦⠀⠀⠀ ",
	"⠀⠀⣼⣿⣿⠋⠀⠀⠀⠀⠀⠛⠛⢻⣿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣧⠀⠀ ",
	"⠀⢸⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⡇⠀ ",
	"⠀⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠀ ",
	"⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⡟⢹⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⣹⣿⣿⠀ ",
	"⠀⣿⣿⣷⠀⠀⠀⠀⠀⠀⣰⣿⣿⠏⠀⠀⢻⣿⣿⡄⠀⠀⠀⠀⠀⠀⣿⣿⡿⠀ ",
	"⠀⢸⣿⣿⡆⠀⠀⠀⠀⣴⣿⡿⠃⠀⠀⠀⠈⢿⣿⣷⣤⣤⡆⠀⠀⣰⣿⣿⠇⠀ ",
	"⠀⠀⢻⣿⣿⣄⠀⠀⠾⠿⠿⠁⠀⠀⠀⠀⠀⠘⣿⣿⡿⠿⠛⠀⣰⣿⣿⡟⠀⠀ ",
	"⠀⠀⠀⠻⣿⣿⣧⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⠏⠀⠀⠀ ",
	"⠀⠀⠀⠀⠈⠻⣿⣿⣷⣤⣄⡀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣾⣿⣿⠟⠁⠀⠀⠀⠀ ",
	"⠀⠀⠀⠀⠀⠀⠈⠛⠿⣿⣿⣿⣿⣿⣶⣶⣿⣿⣿⣿⣿⠿⠋⠁⠀⠀⠀⠀⠀⠀ ",
	"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠛⠛⠛⠛⠛⠛⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ",
}
--
-- dashboard.setup({
-- 	theme = "doom",
-- 	config = {
-- 		header = {}, --your header
-- 		center = {
-- 			{
-- 				icon = " ",
-- 				icon_hi = "Title",
-- 				desc = "Find File",
-- 				desc_hi = "String",
-- 				key = "b",
-- 				key_hi = "Number",
-- 				action = "lua print(2)",
-- 			},
-- 			{
-- 				icon = " ",
-- 				icon_hi = "Title",
-- 				desc = "Find Dotfiles",
-- 				desc_hi = "String",
-- 				key = "f",
-- 				key_hi = "Number",
-- 				action = "lua print(3)",
-- 			},
-- 		},
-- 		footer = {}, --your footer
-- 	},
-- })

-- dashboard.setup({
-- 	theme = "doom",
-- 	config = {
-- 		header = header,
-- 		center = {
-- 			{
-- 				icon = " ",
-- 				desc = "Find file                       ",
-- 				action = "Telescope find_files find_command=rg,--hidden,--files",
-- 				key = "f f",
-- 			},
--
-- 			{
-- 				icon = " ",
-- 				desc = "File browser                    ",
-- 				action = "Telescope file_browser",
-- 				key = "f b",
-- 			},
--
-- 			{
-- 				icon = " ",
-- 				desc = "Find word                       ",
-- 				action = "Telescope live_grep",
-- 				key = "f w",
-- 			},
--
-- 			{
-- 				icon = " ",
-- 				desc = "Recently latest session           ",
-- 				action = "SessionLoad",
-- 				key = "s",
-- 			},
-- 		},
-- 	},
-- })
--
-- db.custom_header = header
--
-- db.custom_center = {
-- 	{
-- 		icon = " ",
-- 		desc = "Find file                       ",
-- 		action = "Telescope find_files find_command=rg,--hidden,--files",
-- 		shortcut = "f f",
-- 	},
--
-- 	{
-- 		icon = " ",
-- 		desc = "File browser                    ",
-- 		action = "Telescope file_browser",
-- 		shortcut = "f b",
-- 	},
--
-- 	{
-- 		icon = " ",
-- 		desc = "Find word                       ",
-- 		action = "Telescope live_grep",
-- 		shortcut = "f w",
-- 	},
--
-- 	{
-- 		icon = " ",
-- 		desc = "Recently latest session           ",
-- 		action = "SessionLoad",
-- 		shortcut = "s",
-- 	},
-- }
