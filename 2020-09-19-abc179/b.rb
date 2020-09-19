n = gets.to_i

m = 0
cnt = 0
n.times do
  a, b = gets.chomp.split.map(&:to_i)
  if a == b
    cnt += 1
  else
    cnt = 0
  end
  m = [m, cnt].max
end

if m >= 3
  puts "Yes"
else
  puts "No"
end
