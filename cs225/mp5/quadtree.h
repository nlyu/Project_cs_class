/**
 * @file quadtree.h
 * Quadtree class definition.
 * @date Spring 2008
 */

#ifndef QUADTREE_H
#define QUADTREE_H

#include "png.h"
#include "math.h"
/**
 * A tree structure that is used to compress PNG images.
 */
class Quadtree
{
  public:
    /* 
        below is the function write by myself
    */

        //FOR MP5.1
        Quadtree();
        Quadtree(const PNG & source, int resolution);
        Quadtree(Quadtree const & other);
        ~Quadtree();

        Quadtree const & operator=(Quadtree const & other);
        void buildTree(PNG const & source, int resolution);
        RGBAPixel getPixel(int x, int y) const;
        PNG decompress() const;

        //FOR MP5.2
        void clockwiseRotate();
        void prune(int tolerance);
        int pruneSize(int tolerance) const;
        int idealPrune (int numLeaves) const;
       
  private:
    /**
     * A simple class representing a single node of a Quadtree.
     * You may want to add to this class; in particular, it could
     * probably use a constructor or two...
     */
    class QuadtreeNode
    {
      public:
        QuadtreeNode* nwChild; /* pointer to NW child */
        QuadtreeNode* neChild; /* pointer to NE child */
        QuadtreeNode* swChild; /* pointer to SW child */
        QuadtreeNode* seChild; /* pointer to SE child */

        RGBAPixel element; /* the pixel stored as this node's "data" */
    };

    QuadtreeNode* root; /* pointer to root of quadtree */
    int pic_size;

/**** Functions for testing/grading                      ****/
/**** Do not remove this line or copy its contents here! ****/
#include "quadtree_given.h"
    void helper_decompress(PNG & img, QuadtreeNode * ancestor, int x, int y, int pic_size_p) const;
    RGBAPixel helper_getPixel(QuadtreeNode * ancestor, int x, int y, int x_mid, int y_mid, int pic_size_p) const;
    void helper_delete(QuadtreeNode *ancestor);
    QuadtreeNode * helper_copy(QuadtreeNode const * ancestor, int & depth);
    QuadtreeNode * helper_build(PNG const & source, int x, int y, int pic_size_p);
    void helper_rotate(QuadtreeNode * & root);
    void helper_prune(QuadtreeNode * & ancestor, int tolerance);
    bool helper_isprune(QuadtreeNode * & child, QuadtreeNode * & ancestor, int tolerance);
    int helper_difference(RGBAPixel first, RGBAPixel second);
};


#endif
