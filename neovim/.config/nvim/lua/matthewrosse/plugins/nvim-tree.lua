local setup, nvimtree = pcall(require, 'nvim-tree')

if not setup then
  return
end

-- recommended settings from nvim-tree docs
vim.g.loaded = 1
vim.g.loaded_netrwPlugin = 1

vim.cmd([[ highlight NvimTreeIndentMarket guifg=#3FC5FF ]])

nvimtree.setup({
  -- this causes error
  -- view = {
  --   mappings = {
  --     list = {
  --       { key = "u", action = "dir_up" },
  --     },
  --   },
  -- },
  sort_by = "case_sensitive",
  renderer = {
    group_empty = true,
  },
  filters = {
    dotfiles = true,
  },
  actions = {
    open_file = {
      window_picker = {
        enable = false,
      },
    },
  },
})
