vim.g.skip_ts_context_commentstring_module = true
return {
	{
		"nvim-treesitter/nvim-treesitter",
		event = { "BufReadPre", "BufNewFile" },
		build = ":TSUpdate",
		dependencies = {
			"nvim-treesitter/nvim-treesitter-textobjects",
			"windwp/nvim-ts-autotag",
		},
		config = function()
			-- import nvim-treesitter plugin
			local treesitter = require("nvim-treesitter.configs")

			-- configure treesitter
			treesitter.setup({ -- enable syntax highlighting
				highlight = {
					enable = true,
				},
				-- enable indentation
				indent = { enable = true, disable = { "python", "ocaml" } },
				-- enable autotagging (w/ nvim-ts-autotag plugin)
				autotag = {
					enable = true,
					enable_rename = true,
					enable_close = true,
					enable_close_on_slash = false,
				},
				-- ensure these language parsers are installed
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
					"pkl",
					"ruby",
					"elixir",
					"python",
				},
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
}
