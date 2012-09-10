function initTable()
	table = {}
	for i=1, 100 do
		table[i] = {}
		table[i]["a"] = math.random(100)
	end
	return table
end


function switch(table)
	for i,v in ipairs(table) do
		print(v.a)
	end

end

function push(table)

end

table = initTable()
switch(table)