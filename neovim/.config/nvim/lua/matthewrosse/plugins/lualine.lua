local setup, lualine = pcall(require, "lualine")

if not setup then
  return
end

local lualine_dracula = require("lualine.themes.dracula")

lualine.setup({
  options = {
    theme = lualine_dracula
  },
})
