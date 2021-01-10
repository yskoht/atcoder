n = gets.to_i
a = gets.chomp.split.map(&:to_i)
b = gets.chomp.split.map(&:to_i)

s = 0
n.times do |i|
  s += a[i] * b[i]
end

if s == 0
  puts "Yes"
else
  puts "No"
end
