n, k = gets.chomp.split.map(&:to_i)
h = gets.chomp.split.map(&:to_i)

h = h.sort.reverse
h = h[k..-1]
puts h.nil? || h.empty? ? 0 : h.inject(&:+)
