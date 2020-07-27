a, b, c = gets.chomp.split.map(&:to_i)
k = gets.to_i

arr = []
arr.push [a, b, c, 0]

f = false

while !arr.empty?
  t = arr.shift
  x, y, z, cnt = *t
  next if cnt > k
  if x < y && y < z
    f = true
    break
  end
  arr.push([x*2, y, z, cnt+1])
  arr.push([x, y*2, z, cnt+1])
  arr.push([x, y, z*2, cnt+1])
end

if f
  puts "Yes"
else
  puts "No"
end
