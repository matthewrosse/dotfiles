return {
	"williamboman/mason.nvim",
	dependencies = {
		"williamboman/mason-lspconfig.nvim",
		"WhoIsSethDaniel/mason-tool-installer.nvim",
	},
	config = function()
		-- import mason
		local mason = require("mason")

		-- import mason-lspconfig
		local mason_lspconfig = require("mason-lspconfig")

		local mason_tool_installer = require("mason-tool-installer")

		-- enable mason and configure icons
		mason.setup({
			ui = {
				icons = {
					package_installed = "✓",
					package_pending = "➜",
					package_uninstalled = "✗",
				},
			},
		})

		mason_lspconfig.setup({
			-- list of servers for mason to install
			ensure_installed = {
				"bashls",
				"clangd",
				"tsserver",
				"html",
				"cssls",
				"css_variables",
				"dockerls",
				"docker_compose_language_service",
				"emmet_ls",
				"gopls",
				"jsonls",
				"lua_ls",
				"autotools_ls",
				"rust_analyzer",
				"sqlls",
				"templ",
				"vuels",
				"yamlls",
				"tailwindcss",
				"ocamllsp",
				"csharp_ls",
			},
		})

		mason_tool_installer.setup({
			ensure_installed = {
				"prettier", -- prettier formatter
				"stylua", -- lua formatter
				"isort", -- python formatter
				"black", -- python formatter
				"pylint",
				"eslint",
				"ocamlformat",
				"csharpier",
			},
		})
	end,
}
