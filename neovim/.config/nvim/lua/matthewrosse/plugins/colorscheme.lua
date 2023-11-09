return {
	{
		"catppuccin/nvim",
		name = "catppuccin",
		priority = 1000,
		lazy = false,
		opts = {
			flavour = "macchiato",
			transparent_background = true,
			term_colors = true,
			no_italic = true,
			intergrations = {
				cmp = true,
				gitsigns = true,
				nvimtree = true,
				treesitter = true,
				notify = true,
				mini = {
					enabled = true,
					indentscope_color = "",
				},
				harpoon = true,
				lsp_saga = true,
				mason = true,
				which_key = true,
			},
		},
	},
	{
		"folke/tokyonight.nvim",
		priority = 1000,
		lazy = false,
		opts = {
			style = "night",
			light_style = "day",
			transparent = true,
			terminal_colors = true,
		},
	},
}
