return {
	{
		"nvim-treesitter/nvim-treesitter",
		build = ":TSUpdate",
		event = { "BufReadPre", "BufNewFile" },
		dependencies = {
			"windwp/nvim-ts-autotag",
		},
		config = function()
			local configs = require("nvim-treesitter.configs")

			configs.setup({
				ensure_installed = {
					"json",
					"yaml",
					"javascript",
					"typescript",
					"tsx",
					"html",
					"css",
					"markdown",
					"markdown_inline",
					"bash",
					"lua",
					"vim",
					"dockerfile",
					"gitignore",
					"query",
					"sql",
					"go",
					"astro",
					"ocaml",
					"make",
					"c",
					"cpp",
					"csv",
					"rust",
					"templ",
					"toml",
					"xml",
					"zig",
					"ruby",
					"elixir",
					"python",
					"c_sharp",
				},
				sync_install = false,
				highlight = { enable = true },
				indent = { enable = true },
				incremental_selection = {
					enable = true,
					keymaps = {
						init_selection = "<C-space>",
						node_incremental = "<C-space>",
						scope_incremental = false,
						node_decremental = "<bs>",
					},
				},
			})
		end,
	},
	{
		"windwp/nvim-ts-autotag",
		config = function()
			require("nvim-ts-autotag").setup()
		end,
	},
}
