impl Solution {
    pub fn all_cells_dist_order(r: i32, c: i32, r0: i32, c0: i32) -> Vec<Vec<i32>> {
        let mut ans : Vec<Vec<i32>> = Vec::new();
        for i in 0..r {
            for j in 0..c {
                ans.push( vec![i, j] );
            }
        }        

        ans.sort_by(|a, b| ( (a[0]-r0).abs() + (a[1]-c0).abs() ).cmp( &((b[0]-r0).abs() + (b[1]-c0).abs() )) ) ;

        return ans;
    }
}