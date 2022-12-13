local home = os.getenv("HOME")
local db = require("dashboard")

local header_str = "NVIM"
local header = {}
for i = 1, #header_str do
	header[i] = header_str:sub(i, i)
end

db.custom_header = header

db.custom_center = {
	{
		icon = " ",
		desc = "Find file                       ",
		action = "Telescope find_files find_command=rg,--hidden,--files",
		shortcut = "SPC f f",
	},

	{
		icon = " ",
		desc = "File browser                    ",
		action = "Telescope file_browser",
		shortcut = "SPC f b",
	},

	{
		icon = " ",
		desc = "Find word                       ",
		action = "Telescope live_grep",
		shortcut = "SPC f w",
	},

	{
		icon = " ",
		desc = "Open personal dotfiles          ",
		action = "Telescope dotfiles path=" .. home .. "/dotfiles",
		shortcut = "SPC f d",
	},
}
