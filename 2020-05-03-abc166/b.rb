n, k = gets.chomp.split.map(&:to_i)

arr = Array.new(n+1, 0)

k.times do
  d = gets.to_i
  a = gets.chomp.split.map(&:to_i)
  a.each do |i|
    arr[i] += 1
  end
end

puts arr.select{ |a| a == 0 }.size - 1
