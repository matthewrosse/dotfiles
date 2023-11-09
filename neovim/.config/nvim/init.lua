require("matthewrosse.core")
require("matthewrosse.lazy")

local colorscheme = "catppuccin"

local status, _ = pcall(vim.cmd, "colorscheme " .. colorscheme)

if not status then
	print("Colorscheme not found.")
	return
end
