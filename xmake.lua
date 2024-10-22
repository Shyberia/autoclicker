add_rules("plugin.compile_commands.autoupdate", { lsp = "clangd" })
add_rules("mode.debug", "mode.release")
add_requires("imgui v1.91.1-docking", {
	configs = {
		win32 = true,
		dx11 = true,
	},
})

target("bunclicker")
add_packages("imgui")
set_kind("binary")
add_files("src/*.cpp")
add_syslinks("kernel32", "user32", "gdi32", "dwmapi", "dxgi", "d3d11", "d3dcompiler")
