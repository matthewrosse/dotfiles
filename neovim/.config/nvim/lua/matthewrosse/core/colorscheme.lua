require("catppuccin").setup({
	flavour = "macchiato",
	-- background = {
	-- 	dark = "macchiato",
	-- },
	transparent_background = true,
	--no_italic = true,
})

local status, _ = pcall(vim.cmd, "colorscheme catppuccin")

if not status then
	print("Colorscheme not found.")
	return
end
