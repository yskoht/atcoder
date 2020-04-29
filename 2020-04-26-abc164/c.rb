n = gets.to_i
arr = []
n.times do
  arr.push gets
end

puts arr.uniq.size
