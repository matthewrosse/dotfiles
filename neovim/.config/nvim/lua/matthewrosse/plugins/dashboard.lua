return {
	"nvimdev/dashboard-nvim",
	event = "VimEnter",
	config = function()
		require("dashboard").setup({
			-- config
			theme = "hyper",
			config = {
				shortcut = {
					{ desc = "󰊳 Update", group = "@property", action = "Lazy update", key = "u" },
					{
						icon = " ",
						icon_hl = "@variable",
						desc = "Files",
						group = "Label",
						action = "Telescope find_files",
						key = "f",
					},
				},
				packages = {
					enable = true,
				},
				mru = {
					limit = 2,
				},
				project = {
					enable = false,
				},
				footer = {
					"",
					"matthewrosse",
				},
				header = {
					[[                                                ]],
					[[                                          _.oo. ]],
					[[                  _.u[[/;:,.         .odMMMMMM' ]],
					[[               .o888UU[[[/;:-.  .o@P^    MMM^   ]],
					[[              oN88888UU[[[/;::-.        dP^     ]],
					[[             dNMMNN888UU[[[/;:--.   .o@P^       ]],
					[[            ,MMMMMMN888UU[[/;::-. o@^           ]],
					[[            NNMMMNN888UU[[[/~.o@P^              ]],
					[[            888888888UU[[[/o@^-..               ]],
					[[           oI8888UU[[[/o@P^:--..                ]],
					[[        .@^  YUU[[[/o@^;::---..                 ]],
					[[      oMP     ^/o@P^;:::---..                   ]],
					[[   .dMMM    .o@^ ^;::---...                     ]],
					[[  dMMMMMMM@^`       `^^^^                       ]],
					[[ YMMMUP^                                        ]],
					[[  ^^                                            ]],
					[[                                                ]],
				},
			},
		})
	end,
	dependencies = { { "nvim-tree/nvim-web-devicons" } },
}
