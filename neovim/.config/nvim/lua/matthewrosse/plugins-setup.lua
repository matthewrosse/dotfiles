local ensure_packer = function()
	local fn = vim.fn
	local install_path = fn.stdpath("data") .. "/site/pack/packer/start/packer.nvim"
	if fn.empty(fn.glob(install_path)) > 0 then
		fn.system({ "git", "clone", "--depth", "1", "https://github.com/wbthomason/packer.nvim", install_path })
		vim.cmd([[packadd packer.nvim]])
		return true
	end
	return false
end

local packer_bootstrap = ensure_packer()

return require("packer").startup(function(use)
	use("wbthomason/packer.nvim")
	use("nvim-lua/plenary.nvim")
	use("catppuccin/nvim")
	use("tpope/vim-fugitive")
	use("folke/tokyonight.nvim")
	use("christoomey/vim-tmux-navigator")
	use("szw/vim-maximizer") -- maximizes and restores current window
	use("tpope/vim-surround")
	use("vim-scripts/ReplaceWithRegister")
	use("numToStr/Comment.nvim")

	use("nvim-tree/nvim-tree.lua")
	use("nvim-tree/nvim-web-devicons")

	use("nvim-lualine/lualine.nvim")
	use("nvim-treesitter/nvim-treesitter-context")
	use({ "nvim-telescope/telescope-fzf-native.nvim", run = "make" })
	use({ "nvim-telescope/telescope.nvim", branch = "0.1.x", requires = { { "nvim-lua/plenary.nvim" } } })
	use("nvim-telescope/telescope-file-browser.nvim")

	use({
		"windwp/nvim-autopairs",
		config = function()
			require("nvim-autopairs").setup({})
		end,
	})

	use({
		"lewis6991/gitsigns.nvim",
		config = function()
			require("gitsigns").setup()
		end,
	})

	-- autocompletion
	--
	use("hrsh7th/nvim-cmp")
	use("hrsh7th/cmp-buffer")
	use("hrsh7th/cmp-path")

	-- snippets
	use("L3MON4D3/LuaSnip") -- snippet engine
	use("saadparwaiz1/cmp_luasnip") -- for autocompletion
	use("rafamadriz/friendly-snippets") -- useful snippets

	use("williamboman/mason.nvim")
	use("williamboman/mason-lspconfig.nvim")
	use("neovim/nvim-lspconfig")

	use("hrsh7th/cmp-nvim-lsp") -- for autocompletion
	use({ "glepnir/lspsaga.nvim", branch = "main" }) -- enhanced lsp uis
	use("jose-elias-alvarez/typescript.nvim") -- additional functionality for typescript server (e.g. rename file & update imports)
	use("onsails/lspkind.nvim") -- vs-code like icons for autocompletion

	-- formatting & linting
	use("jose-elias-alvarez/null-ls.nvim") -- configure formatters & linters
	use("jayp0521/mason-null-ls.nvim") -- bridges gap b/w mason & null-ls

	-- treesitter configuration
	use({
		"nvim-treesitter/nvim-treesitter",
		run = function()
			local ts_update = require("nvim-treesitter.install").update({ with_sync = true })
			ts_update()
		end,
	})

	use({ "windwp/nvim-ts-autotag", after = "nvim-treesitter" }) -- autoclose tags

	use({
		"glepnir/dashboard-nvim",
		event = "VimEnter",
		config = function()
			require("dashboard").setup({
				-- 		-- config
				theme = "hyper",
				-- 		config = {
				-- 			week_header = {
				-- 				enable = true,
				-- 			},
				-- 			shortcut = {
				-- 				{ desc = " Update", group = "@property", action = "PackerSync", key = "u" },
				-- 				{
				-- 					icon = " ",
				-- 					icon_hl = "@variable",
				-- 					desc = "Files",
				-- 					group = "Label",
				-- 					action = "Telescope find_files",
				-- 					key = "f",
				-- 				},
				-- 				{
				-- 					icon = "📁 ",
				-- 					icon_hl = "@variable",
				-- 					desc = "File browser",
				-- 					group = "Label",
				-- 					action = "Telescope file_browser",
				-- 					key = "b",
				-- 				},
				-- 			},
				-- 		},
			})
		end,
		requires = { "nvim-tree/nvim-web-devicons" },
	})

	use("folke/zen-mode.nvim")

	use("ThePrimeagen/harpoon")

	-- Automatically set up your configuration after cloning packer.nvim
	-- Put this at the end after all plugins
	vim.cmd([[
    augroup packer_user_config
      autocmd!
      autocmd BufWritePost plugins-setup.lua source <afile> | PackerSync
    augroup end
  ]])

	if packer_bootstrap then
		require("packer").sync()
	end
end)
