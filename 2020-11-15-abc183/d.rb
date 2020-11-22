n, w = gets.chomp.split.map(&:to_i)
arr = []
n.times do
  s, t, p = gets.chomp.split.map(&:to_i)
  arr.push [s, 1, p]
  arr.push [t, 0, p]
end

arr = arr.sort_by{ |x| [x[0], x[1]] }

f = true
v = 0
arr.each do |a|
  time, type, p = *a
  if type == 1
    v += p
  else
    v -= p
  end

  if v > w
    f = false
    break
  end
end

if f
  puts "Yes"
else
  puts "No"
end
