io.write("This is coming from lua.\n")


function onLoad(n)
	io.write("This is coming from lua.onLoad.\n")
	io.write(n.test())
	io.write("\n")
end

function displayTestInformation()
	io.write("this is for testing method call from c++")
end